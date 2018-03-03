import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemIcon } from 'material-ui/List';
import Avatar from 'material-ui/Avatar';
import ButtonBase from 'material-ui/ButtonBase';
import TextField from 'material-ui/TextField';
import Modal from 'material-ui/Modal';
import Typography from 'material-ui/Typography';
import Card, { CardActions, CardContent } from 'material-ui/Card';
import Button from 'material-ui/Button';

const styles = theme => ({
  avatarButton: {
    width: '40px',
    height: '40px',
  },
  avatarManagerModal: {
    position: 'absolute',
    backgroundColor: theme.palette.background.paper,
    
    [theme.breakpoints.up('sm')]: {
      top: '25%',
      left: '25%',
      width: '50%',
    },

    [theme.breakpoints.down('sm')]: {
      top: '0',
      left: '0',
      width: '100%',
    },
  },
});

class Profile extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {
      avatarManagerModalOpened: false,
      avatarSrc: props.avatarSrc,
    }

    this._state = {
      nickname: props.nickname,
    }

    this.openAvatarManagerModal = this.openAvatarManagerModal.bind(this);
    this.handleAvatarManagerValueChange = this.handleAvatarManagerValueChange.bind(this);
    this.handleOkAvatarManagerModal = this.handleOkAvatarManagerModal.bind(this);
    
    this.handleNicknameChanged = this.handleNicknameChanged.bind(this);
  }

  openAvatarManagerModal = function() {
    this.setState((prevState, props) => ({
      avatarManagerModalOpened: true,
      avatarSrc: prevState.avatarSrc,
    }));
  }

  handleOkAvatarManagerModal = function() {
    this.setState((prevState, props) => ({
      avatarManagerModalOpened: false,
      avatarSrc: prevState.avatarSrc,
    }));
  }

  handleAvatarManagerValueChange = function(event) {
    var value = event.target.value;
    this.props.avatarSrcCallback(value);

    this.setState((prevState, props) => ({
      avatarManagerModalOpened: prevState.avatarManagerModalOpened,
      avatarSrc: value,
    }));
  }

  handleNicknameChanged = function(event) { 
    var value = event.target.value;
    this.props.nicknameCallback(value);
  }

  componentWillReceiveProps = function(nextProps) {
    this._state.nickname = nextProps.nickname;

    this.setState((prevState, props) => ({
      avatarManagerModalOpened: prevState.avatarManagerModalOpened,
      avatarSrc: nextProps.avatarSrc,
    }));
  }

  render() {
    return (
      <ListItem>
        <ListItemIcon>
          <ButtonBase 
            centerRipple
            onClick={ this.openAvatarManagerModal }
            className={ this.classes.avatarButton }
          >
            <Avatar src={ this.state.avatarSrc }>
              { this.state.avatarSrc ? null : this._state.nickname.charAt(0) }
            </Avatar>
          </ButtonBase>
        </ListItemIcon>
        <TextField
          defaultValue={ this._state.nickname }
          onChange={ this.handleNicknameChanged }
          label="Name"
          fullWidth
        />

        <Modal
          open={ this.state.avatarManagerModalOpened }
          onClose={ this.handleOkAvatarManagerModal }
        >
          <div className={ this.classes.avatarManagerModal }>
            <Card>
              <CardContent>
                <TextField
                  fullWidth
                  multiline
                  rows={10}
                  defaultValue={ this.state.avatarSrc }
                  onChange={ this.handleAvatarManagerValueChange }
                />
              </CardContent>
              <CardActions>
                <Button 
                  color="primary"
                  onClick={ this.handleOkAvatarManagerModal }
                >
                  Ok
                </Button>
              </CardActions>
            </Card>
          </div>
        </Modal>

      </ListItem>
    );
  }
}

Profile.propTypes = {
  classes: PropTypes.object.isRequired,
  avatarSrc: PropTypes.string,
  nickname: PropTypes.string,
  avatarSrcCallback: PropTypes.func,
  nicknameCallback: PropTypes.func,
};

Profile.defaultProps = {
  avatarSrc: "",
  nickname: "",
  avatarSrcCallback: ((newAvatarSrc) => {}),
  nicknameCallback: ((newNickname) => {}),
};

export default withStyles(styles)(Profile);