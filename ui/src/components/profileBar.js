import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import Typography from 'material-ui/Typography';
import Avatar from 'material-ui/Avatar';
import ButtonBase from 'material-ui/ButtonBase';
import Badge from 'material-ui/Badge';
import MediaAvatar from './mediaAvatar';
import 'typeface-roboto';
import classnames from 'classnames';

const styles = theme => ({
  profileBar: {
    overflow: 'hidden',
    minHeight: '120px',
    padding: '10px',
    backgroundColor: theme.palette.primary.main,
  },
  avatarButton: {
    '&:after': {
      borderRadius: '50%',
      content: "''",
      width: '10px',
      height: '10px',
      position: 'absolute',
      bottom: '0',
      right: '0',
    },
  },
  offlineConnectionStatus: {
    '&:after': {
      backgroundColor: "transparent",
    }
  },
  noneConnectionStatus: {
    '&:after': {
      backgroundColor: "#76FF03",
    }
  },
  awayConnectionStatus: {
    '&:after': {
      backgroundColor: "#FFEA00",
    }
  },
  busyConnectionStatus: {
    '&:after': {
      backgroundColor: "#FF3D00",
    }
  },
  profileBarAvatar: {
    width: '50px',
    height: '50px',
    margin: '10px',
    backgroundColor: theme.palette.secondary.main,
  },
  profileBarNickname: {
    fontWeight: '500',
    fontSize: '14px',
    color: theme.palette.primary.contrastText,
  },
  profileBarStatus: {
    fontWeight: '300',
    color: theme.palette.primary.contrastText,
  },
  badgeStyle: {
    color: 'green',
    fontSize: '20px !important',

  },
});

class ProfileBar extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {};
  }

  handleProps(props) {
    var result = {
      nickname: props.nickname || "User",
      statusMessage: props.statusMessage || "User status",
      avatarSrc: props.avatarSrc || "",  
      connectionStatus: props.connectionStatus || "offline",
      avatarClickCallback: props.avatarClickCallback || (() => {}),
    }
    return result;
  }

  render() {
    this.safeProps = this.handleProps(this.props);
    return (
      <Grid item align="center" className={ this.classes.profileBar }>
        <Grid item>
          <ButtonBase centerRipple className={ 
            classnames(this.classes.avatarButton, this.classes[this.safeProps.connectionStatus + 'ConnectionStatus']) 
          } onClick={ this.safeProps.avatarClickCallback }>
            <Avatar className={ this.classes.profileBarAvatar } alt="User avatar" src={ this.safeProps.avatarSrc }>
              { this.safeProps.avatarSrc ? null : this.safeProps.nickname.charAt(0) }
            </Avatar>
          </ButtonBase>
        </Grid>
        <Grid item xs={10}>
          <Typography align="center" noWrap gutterBottom className={ this.classes.profileBarNickname }>
            { this.safeProps.nickname }
          </Typography>
        </Grid>
        <Grid item xs={10}>
          <Typography variant="caption" align="center" noWrap gutterBottom className={ this.classes.profileBarStatus }>
            { this.safeProps.statusMessage }
          </Typography>
        </Grid>
      </Grid>
    );
  }
}

ProfileBar.propTypes = {
  classes: PropTypes.object.isRequired,
  avatarSrc: PropTypes.string,
  nickname: PropTypes.string,
  statusMessage: PropTypes.string,
};

export default withStyles(styles)(ProfileBar);
