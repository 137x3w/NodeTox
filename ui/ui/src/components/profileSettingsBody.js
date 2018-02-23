import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List, { ListItem, ListItemIcon, ListSubheader } from 'material-ui/List';
import TextField from 'material-ui/TextField';
import Typography from 'material-ui/Typography';
import Button from 'material-ui/Button';
import Avatar from 'material-ui/Avatar';
import ButtonBase from 'material-ui/ButtonBase';

const styles = theme => ({
  profileSettingsBodyBody: {
    height: 'calc(100vh - 80px)',
    overflow: 'auto',
  },
  profileSettingsBodyAvatar: {
    cursor: 'pointer',
  },
  profileSettingsBodyIcon: {
    width: '40px',
    height: '40px',
  },
  profileSettingsBodyToxid: {
    flex: 1,
  },
  saveButton: {
    justifyContent: 'flex-end',
  }
});

class ProfileSettingsBody extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <Grid item className={ this.classes.profileSettingsBodyBody }>
        <List>
          <ListItem className={ this.classes.saveButton }>
            <Button color="secondary" >
              Save
            </Button>
          </ListItem>
          <ListSubheader disableSticky>
            Public
          </ListSubheader>
          <ListItem>
            <ListItemIcon className={ this.classes.profileSettingsBodyIcon }>
              <ButtonBase centerRipple>
                <Avatar className={ this.classes.profileSettingsBodyAvatar } alt="User avatar" src={ this.props.avatarSrc }>
                  { this.props.avatarSrc ? null : this.props.nickname.charAt(0) }
                </Avatar>
              </ButtonBase>
            </ListItemIcon>
            <TextField
              defaultValue={ this.props.nickname }
              label="Name"
              fullWidth
            />
          </ListItem>
          <ListItem>

            <TextField              
              defaultValue={ this.props.statusMessage }
              label="Status"
              fullWidth
            />
          </ListItem>
          <ListSubheader>
            Tox ID
          </ListSubheader>
          <ListItem>
            <Typography noWrap variant="subheading" className={ this.classes.profileSettingsBodyToxid }>
              { this.props.toxid }
            </Typography>
            <Button>
              QR Image
            </Button>
          </ListItem>
        </List>
      </Grid>
    );
  }
} 

ProfileSettingsBody.propTypes = {
  classes: PropTypes.object.isRequired,
  nickname: PropTypes.string,
  statusMessage: PropTypes.string,
  toxid: PropTypes.string,
  profilePassword: PropTypes.string,
  avatarSrc: PropTypes.string,
};

ProfileSettingsBody.defaultProps = {
  nickname: "Default nickname",
  statusMessage: "Default status message",
  toxid: "Default toxid",
  profilePassword: "",
  avatarSrc: "",
}

export default withStyles(styles)(ProfileSettingsBody);
