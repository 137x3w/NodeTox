import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List, { ListItem, ListItemIcon, ListItemSecondaryAction, ListItemText, ListSubheader } from 'material-ui/List';
import TextField from 'material-ui/TextField';
import Typography from 'material-ui/Typography';
import Button from 'material-ui/Button';
import FingerprintIcon from 'material-ui-icons/Fingerprint';
import ShortTextIcon from 'material-ui-icons/ShortText';
import Avatar from 'material-ui/Avatar';
import ButtonBase from 'material-ui/ButtonBase';

const styles = theme => ({
  profileSettingsBody: {
    height: 'calc(100vh - 80px)',
    overflow: 'auto',
  },
  profileSettingsAvatar: {
    cursor: 'pointer',
  },
  profileSettingsIcon: {
    width: '40px',
    height: '40px',
  },
  profileSettingsToxid: {
    flex: 1,
  },
});

class ProfileSettings extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      nickname: props.nickname || "User",
      status: props.status || "Status",
      toxid: props.toxid || "DD5149809F2320BC81215D2A363A95778D39A0BC260BE7DC90923A933552C765A21E305E722C",
      pass: props.pass || "",
      avatarSrc: props.avatarSrc || "",
    }
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <Grid item className={ this.classes.profileSettingsBody }>
        <List subheader={<ListSubheader disableSticky>Public</ListSubheader>}>
          <ListItem>
            <ListItemIcon className={ this.classes.profileSettingsIcon }>
              <ButtonBase centerRipple>
                <Avatar className={ this.classes.profileSettingsAvatar } alt="User avatar" src={ this.state.avatarSrc }>
                  { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
                </Avatar>
              </ButtonBase>
            </ListItemIcon>
            <TextField
              defaultValue={ this.state.nickname }
              label="Name"
              fullWidth
            />
          </ListItem>
          <ListItem>
            <ListItemIcon className={ this.classes.profileSettingsIcon }>
              <ShortTextIcon/>
            </ListItemIcon>
            <TextField              
              defaultValue={ this.state.status }
              label="Status"
              fullWidth
            />
          </ListItem>
          <ListSubheader>
            Tox ID
          </ListSubheader>
          <ListItem>
            <ListItemIcon className={ this.classes.profileSettingsIcon }>
              <FingerprintIcon/>
            </ListItemIcon>
            <Typography noWrap variant="subheading" className={ this.classes.profileSettingsToxid }>
              { this.state.toxid }
            </Typography>
            <Button>
              Copy
            </Button>
            <Button>
              QR Image
            </Button>
          </ListItem>
        </List>
      </Grid>
    );
  }
} 

ProfileSettings.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ProfileSettings);
